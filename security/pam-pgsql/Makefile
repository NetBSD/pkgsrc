# $NetBSD: Makefile,v 1.2 2014/01/01 11:52:33 wiz Exp $

DISTNAME=	pam-pgsql-0.7.3.1
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pam-pgsql/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/project/pam-pgsql/
COMMENT=	PAM module to authenticate using a PostgreSQL database
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

CONFIGURE_ARGS+=	--pammoddir=${PREFIX:Q}/lib/security

.include "../../security/libgcrypt/buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/pam.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
