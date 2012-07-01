# $NetBSD: Makefile,v 1.20 2012/07/01 15:27:43 jmmv Exp $
#

.include "Makefile.common"

PKGREVISION=	1

COMMENT:=	${COMMENT} - Runtime tools (deprecated)

XML_ENTRIES=	public "-//NetBSD//DTD ATF Tests Results 0.1//EN" \
		${PREFIX}/share/xml/atf/tests-results.dtd

post-install:
.for file in bin/atf-sh \
	     include/ \
	     lib/ \
	     libexec/ \
	     ${PKGMANDIR}/man1/atf-check.1 \
	     ${PKGMANDIR}/man1/atf-sh.1 \
	     ${PKGMANDIR}/man1/atf-test-program.1 \
	     ${PKGMANDIR}/man3/ \
	     ${PKGMANDIR}/man4/ \
	     share/aclocal/ \
	     share/atf/libatf-sh.subr \
	     tests/atf/atf-c++ \
	     tests/atf/atf-c \
	     tests/atf/atf-sh \
	     tests/atf/test-programs
	rm -rf ${DESTDIR}${PREFIX}/${file}
.endfor

.include "../../devel/atf-libs/buildlink3.mk"
.include "../../textproc/xmlcatmgr/catalogs.mk"
.include "../../mk/bsd.pkg.mk"
