# $NetBSD: Makefile,v 1.7 2017/06/05 14:24:40 ryoon Exp $
#

DISTNAME=	HTML-FormatText-WithLinks-AndTables-0.07
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~sfryer/HTML-FormatText-WithLinks-AndTables/
COMMENT=	Converts HTML to Text with tables in tact
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-HTML-FormatText-WithLinks>=0:../../textproc/p5-HTML-FormatText-WithLinks

PERL5_PACKLIST=	auto/HTML/FormatText/WithLinks/AndTables/.packlist
USE_LANGUAGES=	# none

post-install:
	${CHMOD} -x ${DESTDIR}${PREFIX}/${PERL5_SUB_INSTALLVENDORLIB}/HTML/FormatText/WithLinks/AndTables.pm

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
