# $NetBSD: Makefile,v 1.3 2000/01/27 13:49:44 hubertf Exp $
#

DISTNAME=		openssh-1.2.1pre26
PKGNAME=		openssh-1.2.1.26
CATEGORIES=		security
MASTER_SITES=		ftp://thermo.stat.ncsu.edu/pub/openssh/files/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.openssh.org/

CONFLICTS=		ssh-*

USE_PERL5=		yes

RESTRICTED=		"Crypto; export-controlled"
MIRROR_DISTFILE=	no

# matches what's in `Configure' (except sparc64)
ONLY_FOR_PLATFORM=	NetBSD-*-alpha NetBSD-*-arm32 NetBSD-*-i386 \
			NetBSD-*-m68k NetBSD-*-mips NetBSD-*-mipseb \
			NetBSD-*-mipsel NetBSD-*-ns32k NetBSD-*-powerpc \
			NetBSD-*-sparc NetBSD-*-vax

GNU_CONFIGURE=		yes

.include "../../mk/bsd.prefs.mk"

# from mk.conf
SSH_CONF_DIR?=		/etc
CONFIGURE_ARGS=		--prefix=${PREFIX} --sysconfdir=${SSH_CONF_DIR}

DEPENDS=		openssl-0.9.4:../../security/openssl

CONFIGURE_ARGS+=	openssl

.include "../../mk/bsd.pkg.mk"
