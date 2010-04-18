# $NetBSD: Makefile,v 1.4 2010/04/18 18:22:43 jmmv Exp $

.include "../../sysutils/gamin/Makefile.common"
PKGNAME=	${DISTNAME:S/^gamin/lib&/}

PKGREVISION=	1

CONFIGURE_ARGS+=	--enable-libgamin

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	cd ${WRKSRC}/doc; for file in *.html *.gif *.txt *.xml; do	\
		${INSTALL_DATA} $$file ${DESTDIR}${DOCDIR}/$$file;	\
	done

.include "options.mk"
.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
BUILDLINK_TRANSFORM+=	rm:-Wl,--version-script=./gamin_sym.version
.endif

.include "../../mk/bsd.pkg.mk"
