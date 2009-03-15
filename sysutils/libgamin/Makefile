# $NetBSD: Makefile,v 1.1.1.1 2009/03/15 21:29:14 jmcneill Exp $

.include "../../sysutils/gamin/Makefile.common"
PKGNAME=	${DISTNAME:S/^gamin/lib&/}

CONFIGURE_ARGS+=	--enable-libgamin

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	cd ${WRKSRC}/doc; for file in *.html *.gif *.txt *.xml; do	\
		${INSTALL_DATA} $$file ${DESTDIR}${DOCDIR}/$$file;	\
	done

.include "../../mk/bsd.pkg.mk"
