# $NetBSD: Makefile,v 1.13 2000/09/02 18:49:38 wiz Exp $
#

DISTNAME=		coda-4.6.6
PKGNAME=		coda-client-4.6.6.1
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.coda.cs.cmu.edu/pub/coda/src/
EXTRACT_SUFX=		.tgz

MAINTAINER=		rvb@cs.cmu.edu
HOMEPAGE=		http://www.coda.cs.cmu.edu/

DEPENDS+=		gdbm>=1.7.3:../../databases/gdbm
DEPENDS+=		readline>=4.0:../../devel/readline

ONLY_FOR_PLATFORM=	NetBSD-*-*
NOT_FOR_PLATFORM=	NetBSD-*-alpha	# needs custom asm.

ALL_TARGET=		coda
INSTALL_TARGET=		client-install

USE_PERL5=		yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes

pre-configure:
	cd ${WRKSRC} &&							\
	for F in coda-src/advice/Makefile.in; do 		\
		${SED} -e "s_-lgdbm_-Wl,-R${PREFIX}/lib -L${PREFIX}/lib -lgdbm_"\
			< $$F > $$F.patched &&			\
		${MV} $$F.patched $$F;				\
	done

.include "../../mk/bsd.pkg.mk"
