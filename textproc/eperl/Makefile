# $NetBSD: Makefile,v 1.6 2001/02/06 03:17:01 fredb Exp $
#

DISTNAME=	eperl-2.2.14
CATEGORIES=	lang perl5 textproc
MASTER_SITES=	http://www.engelschall.com/sw/eperl/distrib/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.engelschall.com/sw/eperl/

BUILD_DEPENDS+=	${LOCALBASE}/bin/autoreconf:../../devel/autoconf
DEPENDS=	libperl-5.*:../../lang/libperl

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Parse/ePerl/.packlist

GNU_CONFIGURE=	# defined
ALL_TARGET=	all libeperl.a

pre-configure:
	cd ${WRKSRC} && ${LOCALBASE}/bin/autoreconf

post-build:
	cd ${WRKSRC}/mod/Parse; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL
	cd ${WRKSRC}/mod/Parse; ${MAKE_PROGRAM}

post-install:
	cd ${WRKSRC}/mod/Parse; ${MAKE_PROGRAM} install

.include "../../mk/bsd.pkg.mk"
