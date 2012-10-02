# $NetBSD: Makefile,v 1.26 2012/10/02 21:25:36 asau Exp $
#

DISTNAME=	tokyocabinet-perl-1.33
PKGNAME=	p5-${DISTNAME:S/-perl-/-/}
PKGREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	${HOMEPAGE:S/perldoc/perlpkg/}

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://fallabs.com/tokyocabinet/perldoc/
COMMENT=	Perl binding of Tokyo Cabinet
LICENSE=	gnu-lgpl-v2.1

PERL5_PACKLIST=	auto/TokyoCabinet/.packlist

REPLACE_PERL=	*.pl

INSTALLATION_DIRS+=	share/tokyocabinet/doc/perl

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/index.html \
		${DESTDIR}${PREFIX}/share/tokyocabinet/doc/perl/index.html

BUILDLINK_API_DEPENDS.tokyocabinet+=	tokyocabinet>=1.4.29
.include "../../databases/tokyocabinet/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
