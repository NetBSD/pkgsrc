BDF0!=	find .. -type f -a -name \*.bdf -print
BDF=	${BDF0:C/.*\///}
PCF=	${BDF:C/bdf$/pcf/}
PCFALL!=find . -type f -a -name \*.pcf -print

.SUFFIXES:	.bdf .pcf

.bdf.pcf:
	bdftopcf -o $@ $<

all: ${PCF}

prepare::
	for i in ${BDF0}; do \
		ln -s $$i; \
	done

install::
	for i in ${PCFALL}; do \
		${BSD_INSTALL_DATA} $$i ${FONTDIR}; \
		${GZIP_CMD} ${FONTDIR}/$$i; \
	done

clean:
	rm -f *.bdf *.pcf
