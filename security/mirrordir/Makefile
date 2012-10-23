# $NetBSD: Makefile,v 1.15 2012/10/23 18:16:36 asau Exp $
#

DISTNAME=	mirrordir-0.10.49
PKGREVISION=	2
CATEGORIES=	security net
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	# http://mirrordir.sourceforge.net/
COMMENT=	Directory mirroring tool

CONFLICTS=	qmail>=1.03nb7 netqmail>=1.05

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

EGDIR=		${PREFIX}/share/examples/mirrordir

MAKE_DIRS+=	${PKG_SYSCONFDIR}/ssocket
MAKE_DIRS+=	${PKG_SYSCONFDIR}/pam.d

CONF_FILES=	${EGDIR}/secure-mcservusers ${PKG_SYSCONFDIR}/secure-mcservusers
CONF_FILES+=	${EGDIR}/ssocket/accept.cs ${PKG_SYSCONFDIR}/ssocket/accept.cs
CONF_FILES+=	${EGDIR}/ssocket/arcencrypt.cs ${PKG_SYSCONFDIR}/ssocket/arcencrypt.cs
CONF_FILES+=	${EGDIR}/ssocket/arcinit.cs ${PKG_SYSCONFDIR}/ssocket/arcinit.cs
CONF_FILES+=	${EGDIR}/ssocket/connect.cs ${PKG_SYSCONFDIR}/ssocket/connect.cs
CONF_FILES+=	${EGDIR}/pam.d/secure-mcserv ${PKG_SYSCONFDIR}/pam.d/secure-mcserv

.include "../../mk/bsd.pkg.mk"
