# $NetBSD: Makefile,v 1.1.1.1 2006/07/09 15:12:15 wiz Exp $
#

DISTNAME=		magicrescue-1.1.4
CATEGORIES=		sysutils
MASTER_SITES=		http://jbj.rapanden.dk/magicrescue/release/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://jbj.rapanden.dk/magicrescue/release/
COMMENT=		Recover files from a block device by scanning for magic bytes

USE_TOOLS+=		perl:run
HAS_CONFIGURE=		yes

REPLACE_PERL=		tools/elfextract.pl \
			tools/gimp-resave.pl \
			tools/gzip_rename.pl \
			tools/laola.pl \
			tools/mp3extract.pl \
			tools/ole_rename.pl \
			tools/oleextract.pl \
			tools/pngextract.pl \
			tools/script_rename.pl

.include "../../mk/bsd.pkg.mk"
