# $NetBSD: Makefile,v 1.21 2003/01/10 07:43:57 cjep Exp $
#

DISTNAME=		jwhois-3.2.0
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_GNU:=jwhois/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gnu.org/software/jwhois/
COMMENT=		Configurable WHOIS client

USE_BUILDLINK2=		# defined
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--localstatedir=/var/db
CONFIGURE_ARGS+=	--with-cache

INFO_FILES=		jwhois.info

EGDIR=			${PREFIX}/share/examples
CONF_FILES=		${EGDIR}/jwhois.conf ${PKG_SYSCONFDIR}/jwhois.conf
CONF_FILES_PERMS=	/dev/null /var/db/jwhois.db			\
			${ROOT_USER} nogroup 0664
post-install:
	${INSTALL_DATA} ${WRKSRC}/example/jwhois.conf ${PREFIX}/share/examples

.include "../../devel/gettext-lib/buildlink2.mk"

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
