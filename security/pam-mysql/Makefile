# $NetBSD: Makefile,v 1.23 2023/10/24 22:10:55 wiz Exp $

DISTNAME=	pam_mysql-0.7RC1
PKGNAME=	${DISTNAME:S/_/-/:S/RC/rc/}
PKGREVISION=	11
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pam-mysql/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pam-mysql.sourceforge.net/
COMMENT=	PAM module for authenticating with MySQL

DOCDIR=		${PREFIX}/share/doc/pam-mysql

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

CONFIGURE_ARGS+=	--with-mysql=${BUILDLINK_PREFIX.mysql-client:Q}
CONFIGURE_ARGS+=	--with-pam-mods-dir=${PREFIX:Q}/lib/security
CONFIGURE_ARGS+=	--with-pam=${PAMBASE:Q}
CONFIGURE_ARGS+=	--disable-static

INSTALLATION_DIRS=	${DOCDIR}

post-install:
	cd ${WRKSRC:Q} && ${INSTALL_DATA} CREDITS ChangeLog README ${DESTDIR}${DOCDIR}

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/pam.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
