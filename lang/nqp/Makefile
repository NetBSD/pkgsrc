# $NetBSD: Makefile,v 1.49 2024/03/09 05:23:51 mef Exp $

DISTNAME=	nqp-2024.02
CATEGORIES=	lang perl6
#ASTER_SITES=	${MASTER_SITE_GITHUB:=perl6/}
MASTER_SITES=	https://github.com/perl6/nqp/releases/download/${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://rakudo.org/
COMMENT=	Not Quite Perl -- lightweight Perl 6-like environment for VM
LICENSE=	artistic-2.0

DEPENDS+=	MoarVM>=2022.03:../../devel/MoarVM

MAKE_JOBS_SAFE=	no

.include "../../mk/bsd.prefs.mk"

USE_LANGUAGES=		c c++
USE_TOOLS+=		perl gmake

HAS_CONFIGURE=		yes
CONFIG_SHELL=		${PERL5}
CONFIGURE_SCRIPT=	Configure.pl
CONFIGURE_ARGS=		--prefix=${PREFIX:Q} \
			--backends=moar

# lang/rakudo wants these two *.pm on @INC path as well as 3rdparty/nqp..
EXTRA_MODULES+=		Config.pm Macros.pm

# please (or let me ) correct later for hard coding
post-install:
	${INSTALL_DIR}                                   ${DESTDIR}${PREFIX}/lib/perl5/site_perl/5.38.0/NQP
	(cd ${WRKSRC} ; \
	for i in ${EXTRA_MODULES} ; \
	do \
	${INSTALL}  3rdparty/nqp-configure/lib/NQP/$${i} ${DESTDIR}${PREFIX}/lib/perl5/site_perl/5.38.0/NQP ; \
	done ; \
	)

.include "../../devel/MoarVM/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
