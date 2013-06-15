# $NetBSD: Makefile,v 1.5 2013/06/15 22:49:06 dholland Exp $

DISTNAME=		smtp-vilter-1.3.8
CATEGORIES=		mail
MASTER_SITES=		${HOMEPAGE}
EXTRACT_SUFX=		.tgz
PKGREVISION=		2

MAINTAINER=		marc@msys.ch
HOMEPAGE=		http://www.etc.msys.ch/software/smtp-vilter/
COMMENT=		milter to scan messages for viruses and spam

USE_BSD_MAKEFILE=	yes

PKG_GROUPS=		vilter
PKG_USERS=		vilter:vilter
PKG_GECOS.vilter=	SMTP vilter

INSTALLATION_DIRS=	etc sbin lib/smtp-vilter man/man5 man/man8

.include "../../mail/libmilter/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
