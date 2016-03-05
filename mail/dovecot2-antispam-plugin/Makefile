# $NetBSD: Makefile,v 1.5 2016/03/05 11:28:47 jperkin Exp $

DISTNAME=		dovecot-antispam-plugin-20130429
PKGREVISION=		3
CATEGORIES=		mail
MASTER_SITES=		http://olgeni.olgeni.com/~olgeni/distfiles/ \
			http://distcache.FreeBSD.org/local-distfiles/olgeni/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://hg.dovecot.org/dovecot-antispam-plugin/
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
