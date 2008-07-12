# XXX snarf and atfify the tests from regress/buildlink-transform

.SUFFIXES: .sh .atf
.sh.atf:
	atf-compile -o ${.TARGET} ${.IMPSRC}

TESTS=		include_pkgdir_slashdot lib-expand quoted_arg remove-dir
TESTFILES=	${TESTS:S/^/test-/g:S/$/.atf/g}
ALLFILES=	Atffile ${TESTFILES}

clean:
	rm -f ${ALLFILES}

test: all
	atf-run

all: ${ALLFILES}

Atffile:
	@echo 'Content-Type: application/X-atf-atffile; version="1"' > Atffile
	@echo >> Atffile
	@echo 'prop: test-suite = "regress-buildlink-transform"' >> Atffile
	@echo >> Atffile
.	for i in ${TESTFILES}
	@echo "tp: ${i}" >> Atffile
.	endfor
