# $NetBSD: Makefile,v 1.15 2006/06/26 18:16:31 wiz Exp $

DISTNAME=	tosha-0.05
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.tu-clausthal.de/pub/unix/audio/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.heim3.tu-clausthal.de/~olli/tosha/
COMMENT=	Read CD digital audio data through the SCSI bus

PKG_INSTALLATION_TYPES=	overwrite pkgviews

CPPFLAGS+=	-DDEVOSSAUDIO="\"${DEVOSSAUDIO}\""

INSTALLATION_DIRS=	bin man/man1

.include "../../devel/libscsi/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
