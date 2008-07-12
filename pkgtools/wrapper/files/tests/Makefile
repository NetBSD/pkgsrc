# $NetBSD: Makefile,v 1.1.2.3 2008/07/12 06:57:49 schmonz Exp $
#

# XXX snarf and atfify the tests from regress/buildlink-transform

.SUFFIXES: .sh .atf
.sh.atf:
	atf-compile -o ${.TARGET} ${.IMPSRC}

TESTS=		include_pkgdir_slashdot lib_expand quoted_arg remove_dir
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
