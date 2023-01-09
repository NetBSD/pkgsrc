# $NetBSD: Makefile,v 1.6 2023/01/09 01:36:10 sekiya Exp $

DISTNAME=	sshguard-2.4.2
#PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sshguard/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.sshguard.net/
COMMENT=	Protect networked hosts from brute force attacks
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes

RCD_SCRIPTS=	sshguard

.include "options.mk"

# Claiming to be an X/Open applications hides inet_pton(3) under NetBSD
# which this application needs.
BUILDLINK_TRANSFORM.NetBSD+=	rm:-D_XOPEN_SOURCE

.include "../../mk/bsd.pkg.mk"
