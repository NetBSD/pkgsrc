# $NetBSD: Makefile,v 1.17 2007/01/07 09:13:47 rillig Exp $

DISTNAME=	tosha-0.05
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	pkgsrc-users@NetBSD.org
# author's homepage is at http://www.secnetix.de/~olli/, but tosha isn't mentioned
COMMENT=	Read CD digital audio data through the SCSI bus

PKG_INSTALLATION_TYPES=	overwrite pkgviews

CPPFLAGS+=	-DDEVOSSAUDIO="\"${DEVOSSAUDIO}\""

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../devel/libscsi/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
