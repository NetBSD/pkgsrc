# $NetBSD: Makefile,v 1.23 2003/02/15 05:18:09 salo Exp $
#

DISTNAME=		jwhois-3.2.1
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_GNU:=jwhois/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gnu.org/software/jwhois/
COMMENT=		Configurable WHOIS client

USE_BUILDLINK2=		YES
USE_PKGINSTALL=		YES
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--localstatedir=/var/db
CONFIGURE_ARGS+=	--with-cache

INFO_FILES=		jwhois.info

EGDIR=			${PREFIX}/share/examples/jwhois
CONF_FILES=		${EGDIR}/jwhois.conf.default	\
			${PKG_SYSCONFDIR}/jwhois.conf
CONF_FILES_PERMS=	/dev/null /var/db/jwhois.db	\
			${ROOT_USER} nogroup 0664
post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/example/jwhois.conf	\
		${EGDIR}/jwhois.conf.default

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
