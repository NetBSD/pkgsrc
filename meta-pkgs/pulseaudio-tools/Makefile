# $NetBSD: Makefile,v 1.2 2010/03/15 04:09:13 dholland Exp $
#

DISTNAME=	pulseaudio-tools-0.9
CATEGORIES=	meta-pkgs audio
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.pulseaudio.org/
COMMENT=	Management tools for PulseAudio

DEPENDS+=	paman-[0-9]*:../../audio/paman
DEPENDS+=	paprefs-[0-9]*:../../audio/paprefs
DEPENDS+=	padevchooser-[0-9]*:../../audio/padevchooser
DEPENDS+=	pavucontrol-[0-9]*:../../audio/pavucontrol
DEPENDS+=	pavumeter-[0-9]*:../../audio/pavumeter

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
