# $NetBSD: Makefile,v 1.18 2002/02/27 01:39:12 tv Exp $
#

DISTNAME=		jwhois-3.1.0
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_GNU:=jwhois/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gnu.org/software/jwhois/
COMMENT=		Configurable WHOIS client

USE_BUILDLINK_ONLY=	# defined
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

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
