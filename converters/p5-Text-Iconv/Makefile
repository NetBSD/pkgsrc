# $NetBSD: Makefile,v 1.2 2001/10/18 15:20:05 veego Exp $
#

DISTNAME=	Text-Iconv-1.1
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5tic
CATEGORIES=	converters perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	abs@netbsd.org
HOMEPAGE=	http://www.linguistik.uni-erlangen.de/~mxp/
COMMENT=	Perl interface to iconv() codeset conversion function

USE_BUILDLINK_ONLY= #defined

.include "../../converters/libiconv/buildlink.mk"

DEPENDS+= 	libiconv:../../converters/libiconv

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Text/Iconv/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
