# $NetBSD: Makefile,v 1.7 2015/01/16 11:47:01 wiz Exp $

.include "../../textproc/docbook-xsl/Makefile.common"

PKGNAME=	dbtoepub-${DISTNAME:S/docbook-xsl-//}
COMMENT=	DocBook to epub converter

DEPENDS+= \
	docbook-xsl>=${DISTNAME:S/docbook-xsl-//}:../../textproc/docbook-xsl

REPLACE_RUBY+=	epub/bin/dbtoepub

INSTALLATION_DIRS+=	${XSLDIR}

do-install:
	${ECHO} "${INSTALL_DATA_DIR} ${DESTDIR}${XSLDIR}/epub"
	${ECHO} "cd ${WRKSRC} && pax -rw -pp -pm epub ${DESTDIR}${XSLDIR}/"
	cd ${WRKSRC} && pax -rw -pp -pm epub ${DESTDIR}${XSLDIR}/
	for f in `${FIND} ${DESTDIR}${XSLDIR} -name \\*.orig -print` ; do \
		${ECHO} "Remove .orig file $$f" ; \
		${RM} $$f ; \
	done

.include "../../lang/ruby/buildlink3.mk"
.include "../../lang/ruby/replace.mk"
.include "../../mk/bsd.pkg.mk"
