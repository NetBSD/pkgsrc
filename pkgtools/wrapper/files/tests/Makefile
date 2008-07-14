# $NetBSD: Makefile,v 1.1.2.5 2008/07/14 05:22:18 schmonz Exp $
#

.SUFFIXES: .sh .atf
.sh.atf:
	atf-compile -o ${.TARGET} ${.IMPSRC}

TESTS!=		echo test-*.sh
TESTFILES=	${TESTS:S/.sh$/.atf/g}
ALLFILES=	Atffile ${TESTFILES}

ATF_REPORT?=	atf-report

clean:
	rm -f ${ALLFILES}

test: all
	atf-run | ${ATF_REPORT}

all: ${ALLFILES}

Atffile:
	@echo 'Content-Type: application/X-atf-atffile; version="1"' > Atffile
	@echo >> Atffile
	@echo 'prop: test-suite = "regress-buildlink-transform"' >> Atffile
	@echo >> Atffile
.	for i in ${TESTFILES}
	@echo "tp: ${i}" >> Atffile
.	endfor
