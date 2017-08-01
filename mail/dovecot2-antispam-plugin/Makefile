# $NetBSD: Makefile,v 1.8 2017/08/01 17:40:13 wiz Exp $

DISTNAME=		dovecot-antispam-plugin-20130429
PKGREVISION=		4
CATEGORIES=		mail
MASTER_SITES=		http://olgeni.olgeni.com/~olgeni/distfiles/
MASTER_SITES+=		http://distcache.FreeBSD.org/local-distfiles/olgeni/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		schmonz@NetBSD.org
#HOMEPAGE=		http://hg.dovecot.org/dovecot-antispam-plugin/
COMMENT=		Dovecot 2.x plugin for training antispam systems
LICENSE=		gnu-gpl-v2

WRKSRC=			${WRKDIR}/dovecot-antispam-plugin-5ebc6aae4d7c

USE_TOOLS+=		aclocal autoheader automake autoconf gmake gawk gsed
AUTOCONF_REQD=		2.54
GNU_CONFIGURE=		yes

OPSYSVARS+=		SUFX
SUFX.Darwin=		bundle
SUFX.*=			so

PLIST_SUBST+=		SUFX=${SUFX:Q}

pre-configure:
	cd ${WRKSRC} && aclocal -I m4 && autoheader && autoconf

.include "../../mail/dovecot2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
