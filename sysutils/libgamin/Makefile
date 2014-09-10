# $NetBSD: Makefile,v 1.5 2014/09/10 15:59:33 jperkin Exp $

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

.if ${OPSYS} == "Darwin" || ${OPSYS} == "SunOS"
BUILDLINK_TRANSFORM+=	rm:-Wl,--version-script=./gamin_sym.version
.endif

.include "../../mk/bsd.pkg.mk"
