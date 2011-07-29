# $NetBSD: Makefile,v 1.53 2011/07/29 15:11:40 bouyer Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../sysutils/ups-nut/Makefile.common"

PKGNAME=		${DISTNAME:S/nut/ups-nut-cgi/}
COMMENT=		Network UPS Tools CGI scripts

DEPENDS+=		ups-nut-2.*:../../sysutils/ups-nut

INSTALLATION_DIRS+=	${NUT_EGDIR}
INSTALLATION_DIRS+=	${PREFIX}/libexec/cgi-bin
INSTALLATION_DIRS+=	${PREFIX}/share/nut/html
INSTALLATION_DIRS+=	${PREFIX}/${PKGMANDIR}/man5
INSTALLATION_DIRS+=	${PREFIX}/${PKGMANDIR}/man8

CONFIGURE_ARGS+=	--with-cgi
CONFIGURE_ARGS+=	--with-cgipath=${NUT_CGIDIR:Q}

BUILD_DEFS+=		NUT_STATEDIR

CONF_FILES=		${NUT_EGDIR}/hosts.conf.sample ${NUT_CONFDIR}/hosts.conf
CONF_FILES+=		${NUT_EGDIR}/upsset.conf.sample		 \
			${NUT_CONFDIR}/upsset.conf
CONF_FILES+=		${NUT_EGDIR}/upsstats-single.html.sample \
			${NUT_CONFDIR}/upsstats-single.html
CONF_FILES+=		${NUT_EGDIR}/upsstats.html.sample \
			${NUT_CONFDIR}/upsstats.html

do-install:
	(cd ${WRKSRC}/clients && env ${MAKE_ENV} \
	    ${MAKE_PROGRAM} ${INSTALL_MAKE_FLAGS} install-cgiexecPROGRAMS)
	for f in hosts.conf.sample upsset.conf.sample \
	    upsstats.html.sample upsstats-single.html.sample; do \
		${INSTALL_DATA} ${WRKSRC}/conf/$$f ${DESTDIR}${NUT_EGDIR}; \
	done
	for f in bottom.html header.html index.html nut-banner.png; do \
		${INSTALL_DATA} ${WRKSRC}/data/html/$$f \
		    ${DESTDIR}${PREFIX}/share/nut/html; \
	done
	for f in hosts.conf.5 upsset.conf.5 upsstats.html.5; do \
		${INSTALL_MAN} ${WRKSRC}/docs/man/$$f \
		    ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5/; \
	done
	for f in upsimage.cgi.8 upsset.cgi.8 upsstats.cgi.8; do \
		${INSTALL_MAN} ${WRKSRC}/docs/man/$$f \
		    ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/; \
	done

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/gd/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
