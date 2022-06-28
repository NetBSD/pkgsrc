# $NetBSD: Makefile,v 1.15 2022/06/28 11:35:58 wiz Exp $
#

DISTNAME=		magicrescue-1.1.4
PKGREVISION=		10
CATEGORIES=		sysutils
#MASTER_SITES=		http://jbj.rapanden.dk/magicrescue/release/

MAINTAINER=		pkgsrc-users@NetBSD.org
#HOMEPAGE=		http://jbj.rapanden.dk/magicrescue/release/
COMMENT=		Recover files from a block device by scanning for magic bytes

USE_TOOLS+=		perl:run
HAS_CONFIGURE=		yes

REPLACE_PERL=		magicsort \
			tools/checkrecipe \
			tools/elfextract.pl \
			tools/gimp-resave.pl \
			tools/gzip_rename.pl \
			tools/laola.pl \
			tools/mp3extract.pl \
			tools/ole_rename.pl \
			tools/oleextract.pl \
			tools/pngextract.pl \
			tools/script_rename.pl

INSTALL_MAKE_FLAGS+=	PREFIX=${DESTDIR}${PREFIX}

.include "../../mk/bsd.pkg.mk"
