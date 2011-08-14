# $NetBSD: Makefile,v 1.3 2011/08/14 08:18:09 obache Exp $
#

DISTNAME=		Net-Cassandra-0.35
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
CATEGORIES=		databases perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=		tonnerre@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Net-Cassandra/
COMMENT=		Perl5 module for accessing the Cassandra database

DEPENDS+=		p5-Bit-Vector>=0:../../devel/p5-Bit-Vector
DEPENDS+=		p5-Moose>=0.56:../../devel/p5-Moose
DEPENDS+=		p5-MooseX-StrictConstructor>=0:../../devel/p5-MooseX-StrictConstructor

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Net/Cassandra/.packlist

post-patch:
	${FIND} ${WRKSRC} -name "*.orig" -exec ${RM} -f {} \;

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
