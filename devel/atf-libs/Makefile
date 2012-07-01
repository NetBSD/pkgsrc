# $NetBSD: Makefile,v 1.1 2012/07/01 15:27:43 jmmv Exp $
#

.include "../../devel/atf/Makefile.common"
PKGNAME=	${DISTNAME:S/-/-libs-/}

COMMENT:=	${COMMENT} - Libraries

post-install:
.for tool in atf-config atf-report atf-run atf-version
	rm -f ${DESTDIR}${PREFIX}/bin/${tool}
	rm -f ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/${tool}.1
	rm -rf ${DESTDIR}${PREFIX}/tests/atf/${tool}
.endfor
.for file in ${PKGMANDIR}/man5/atf-formats.5 \
             ${PKGMANDIR}/man7/atf.7 \
             share/atf/atf-run.hooks \
             share/doc/atf/ \
             share/examples/ \
             share/xml/ \
             share/xsl/ \
             tests/atf/Atffile \
             tests/atf/Kyuafile
	rm -rf ${DESTDIR}${PREFIX}/${file}
.endfor

.include "../../mk/bsd.pkg.mk"
