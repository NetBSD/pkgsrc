# $NetBSD: Makefile,v 1.34 2018/08/22 09:45:25 wiz Exp $

DISTNAME=	grepmail-5.3033
PKGREVISION=	10
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=grepmail/}

MAINTAINER=	david@fundy.net
HOMEPAGE=	http://grepmail.sourceforge.net/
COMMENT=	Search utility for mbox formatted files

DEPENDS+=	p5-Date-Manip-[0-9]*:../../devel/p5-Date-Manip
#DEPENDS+=	{perl>=5.7.3,p5-Digest-MD5-[0-9]*}:../../security/p5-Digest-MD5
DEPENDS+=	p5-TimeDate-[0-9]*:../../time/p5-TimeDate
DEPENDS+=	p5-Mail-Mbox-MessageParser>=1.4001:../../mail/p5-Mail-Mbox-MessageParser

PERL5_PACKLIST=	auto/grepmail/.packlist
MAKE_PARAMS+=	< /dev/null

MAKE_ENV+=	PERL_USE_UNSAFE_INC=1

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
