# $NetBSD: Makefile,v 1.15 2006/06/05 23:34:42 minskim Exp $
#

DISTNAME=		bioperl-0.7.0
PKGREVISION=		2
CATEGORIES=		biology
MASTER_SITES=		http://bioperl.org/Core/Latest/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://bioperl.org/
COMMENT=		Perl tools for computational molecular biology

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

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/bioperl
	cd ${WRKSRC}/examples && ${PAX} -rw . ${PREFIX}/share/examples/bioperl

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
