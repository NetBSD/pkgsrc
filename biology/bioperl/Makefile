# $NetBSD: Makefile,v 1.21 2011/08/14 07:27:39 obache Exp $
#

DISTNAME=		bioperl-0.7.0
PKGREVISION=		5
CATEGORIES=		biology
MASTER_SITES=		http://bioperl.org/DIST/old_releases/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://bioperl.org/
COMMENT=		Perl tools for computational molecular biology

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	pax

REPLACE_PERL+=		Bio/LiveSeq/Chain.pm
REPLACE_PERL+=		Bio/SeqIO/game/featureHandler.pm
REPLACE_PERL+=		Bio/Tools/Blast/Run/postclient.pl
REPLACE_PERL+=		examples/gsequence
REPLACE_PERL+=		examples/*.pl
REPLACE_PERL+=		examples/blast/*.pl
REPLACE_PERL+=		examples/root_object/*.pl
REPLACE_PERL+=		examples/root_object/vector/vector.pl
REPLACE_PERL+=		examples/seq/*.pl

PERL5_PACKLIST=		auto/Bio/.packlist

INSTALLATION_DIRS=	share/examples/bioperl

post-install:
	cd ${WRKSRC}/examples && pax -rw . ${DESTDIR}${PREFIX}/share/examples/bioperl

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
