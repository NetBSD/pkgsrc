# $NetBSD: Makefile,v 1.27 2010/02/14 10:00:09 wiz Exp $
#

DISTNAME=	clive-2.2.9
CATEGORIES=	net multimedia www
MASTER_SITES=	http://clive.googlecode.com/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://clive.sourceforge.net/
COMMENT=	Command line video extraction tool for user-uploaded video hosts
LICENSE=	gnu-gpl-v3

DEPENDS+=	p5-BerkeleyDB>=0.34:../../databases/p5-BerkeleyDB
DEPENDS+=	p5-Class-Singleton-[0-9]*:../../devel/p5-Class-Singleton
DEPENDS+=	p5-Getopt-ArgvFile-[0-9]*:../../devel/p5-Getopt-ArgvFile
DEPENDS+=	p5-Digest-SHA-[0-9]*:../../security/p5-Digest-SHA
DEPENDS+=	p5-HTML-Parser>=2.37:../../www/p5-HTML-Parser
DEPENDS+=	p5-Term-ReadKey-[0-9]*:../../devel/p5-Term-ReadKey
DEPENDS+=	p5-URI>=1.37:../../www/p5-URI
DEPENDS+=	p5-WWW-Curl>=4.05:../../www/p5-WWW-Curl

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/clive/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
