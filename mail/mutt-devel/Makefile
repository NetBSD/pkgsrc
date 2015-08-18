# $NetBSD: Makefile,v 1.105 2015/08/18 07:31:11 wiz Exp $

DISTNAME=		mutt-1.5.23
PKGREVISION=		7
CATEGORIES=		mail
MUTT_SITES=		ftp://ftp.mutt.org/mutt/ \
			ftp://ftp.stealth.net/pub/mirrors/ftp.mutt.org/pub/mutt/ \
			ftp://gd.tuwien.ac.at/infosys/mail/mutt/ \
			ftp://ftp.fu-berlin.de/unix/mail/mutt/
MASTER_SITES=		${MUTT_SITES:=devel/}

MAINTAINER=		tonio@NetBSD.org
HOMEPAGE=		http://www.mutt.org/
COMMENT=		Text-based MIME mail client with PGP & S/MIME support
LICENSE=		gnu-gpl-v2 OR gnu-gpl-v3 # or newer

.include "Makefile.common"

.include "../../mk/bsd.pkg.mk"
