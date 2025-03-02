# $NetBSD: Makefile,v 1.57 2025/03/02 02:15:46 mef Exp $

DISTNAME=	nqp-2025.02
CATEGORIES=	lang perl6
MASTER_SITES=	${MASTER_SITE_GITHUB:=perl6/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://rakudo.org/
COMMENT=	Not Quite Perl -- lightweight Perl 6-like environment for VM
LICENSE=	artistic-2.0

DEPENDS+=	MoarVM>=2022.03:../../devel/MoarVM

# Is this necessary ? Trying to drop (2024.12, set in 2020)
#AKE_JOBS_SAFE=	no

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

# strange, two files have been gone away, and still look necessary, picked from 2025.01 version
pre-configure:
	mkdir -p ${WRKSRC}/3rdparty/nqp-configure/lib/NQP
	cp -p ${FILESDIR}/Config.pm \
	      ${FILESDIR}/Macros.pm \
	${WRKSRC}/3rdparty/nqp-configure/lib/NQP

# please (or let me ) correct later for hard coding
post-install:
	${INSTALL_LIB_DIR} ${DESTDIR}${PREFIX}/lib/perl5/site_perl/5.40.0/NQP
	(cd ${WRKSRC} ; \
	for i in ${EXTRA_MODULES} ; \
	do \
	${INSTALL}  3rdparty/nqp-configure/lib/NQP/$${i} ${DESTDIR}${PREFIX}/lib/perl5/site_perl/5.40.0/NQP ; \
	done ; \
	)

.include "../../devel/MoarVM/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
