include Makefile.inc

MODULES?=	po src server

all: gkrellm.pc build

gkrellm.pc:
ifneq ($(findstring src,$(MODULES)),)
	echo "prefix=$(INSTALLROOT)" > gkrellm.pc
	echo "Name: GKrellM" >> gkrellm.pc
	echo "Description: Extensible GTK system monitoring application" >> gkrellm.pc
	echo "Version: $(VERSION)" >> gkrellm.pc
	echo "Requires: gtk+-2.0 >= 2.0.0" >> gkrellm.pc
	echo "Cflags: -I$(INCLUDEDIR)" >> gkrellm.pc
endif

install:	install-rec install_gkrellm.pc

build:		build-rec
clean:		clean-rec

build-rec install-rec clean-rec uninstall-rec:
	for subdir in $(MODULES); do						\
	cd $$subdir && 								\
	$(MAKE) $(patsubst %-rec,%,$@) MODULE=$$subdir GTOP=$(GTOP) || exit 1;	\
	cd ..;									\
	done

install_gkrellm.pc:
ifneq ($(findstring src,$(MODULES)),)
	$(INSTALL_DIR) $(PKGCONFIGDIR)
	$(INSTALL_DATA) gkrellm.pc $(PKGCONFIGDIR)
endif

uninstall: uninstall-req
ifneq ($(findstring src,$(MODULES)),)
	rm -f $(PKGCONFIGDIR)/gkrellm.pc
endif

gtop gnome-gtop gtop-1.0:
	$(MAKE) build MODULES="$(MODULES)" GTOP=$@

.PHONY: all build intall install_mod install_gkrellm.pc clean	\
	install-rec build-rec clean-rec uninstall uninstall-rec	\
	gtop gnome-gtop gtop-1.0
