include ../Makefile.inc

PACKAGE?=	gkrellm

ifeq ($(ENABLE_NLS),yes)
FILES_PO:=	$(wildcard *.po)
FILES_MO:=	$(FILES_PO:.po=.mo)
else
FILES_MO=
endif

all: build

build: $(FILES_MO)

install: $(FILES_MO)
	for f in $(FILES_MO); do							\
	$(INSTALL_DIR) $(LOCALEDIR)/`basename $$f .mo`/LC_MESSAGES;			\
	$(INSTALL_DATA) $$f $(LOCALEDIR)/`basename $$f .mo`/LC_MESSAGES/$(PACKAGE).mo;	\
	done

uninstall:
ifneq ($(FILES_MO),)
	for f in $(FILES_MO) ; do 							\
	rm -f $(INSTALL_PREFIX)$(LOCALEDIR)/`basename $$f .mo`/LC_MESSAGES/$(PACKAGE).mo ; done
endif

clean:
ifneq ($(FILES_MO),)
	$(RM) $(FILES_MO)
endif

%.mo: %.po
	$(MSGFMT) $(MSGFMT_OPT) -o $@ $<

.PHONY: all build install clean uninstall
