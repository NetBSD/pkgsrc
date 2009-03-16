# $NetBSD: Makefile,v 1.2 2009/03/16 13:06:46 tron Exp $

.include "../../sysutils/gamin/Makefile.common"
PKGNAME=	${DISTNAME:S/^gamin/lib&/}

CONFIGURE_ARGS+=	--enable-libgamin

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	cd ${WRKSRC}/doc; for file in *.html *.gif *.txt *.xml; do	\
		${INSTALL_DATA} $$file ${DESTDIR}${DOCDIR}/$$file;	\
	done

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
BUILDLINK_TRANSFORM+=	rm:-Wl,--version-script=./gamin_sym.version
.endif

.include "../../mk/bsd.pkg.mk"
