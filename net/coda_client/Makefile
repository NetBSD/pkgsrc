# $NetBSD: Makefile,v 1.17 2001/02/17 18:18:42 wiz Exp $
#

DISTNAME=		coda-4.6.6
PKGNAME=		coda-client-4.6.6.1
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.infonoc.ne.jp/pub/coda/src/old/ \
			ftp://ftp.rsu.ru/pub/unix/FileSystems/coda/
EXTRACT_SUFX=		.tgz

MAINTAINER=		rvb@cs.cmu.edu
HOMEPAGE=		http://www.coda.cs.cmu.edu/
COMMENT=		client programs for a replicated high-performance network file system

DEPENDS+=		gdbm>=1.7.3:../../databases/gdbm
DEPENDS+=		readline>=4.0:../../devel/readline

# Requires "lwp" plus "filesystem CODA" to operate. Should build on
# any NetBSD-*-m68k, though.
ONLY_FOR_PLATFORM=	NetBSD-*-i386 NetBSD-*-m68k

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
