# $NetBSD: Makefile,v 1.3 2001/11/26 06:50:24 jlam Exp $
#

DISTNAME=       Text-Wrapper-1.000
PKGNAME=        p5-Text-Wrapper-1.0
SVR4_PKGNAME=	p5twr
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	packages@netbsd.org
COMMENT=	perl5 module that provides simple word wrapping

USE_BUILDLINK_ONLY=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Text/Wrapper/.packlist

do-configure:
	@cd ${WRKSRC} && ${TOUCH} ${TOUCH_ARGS} .test && \
		${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
