# $NetBSD: Makefile,v 1.2 2015/01/14 21:45:13 wiz Exp $

DISTNAME=		dovecot-antispam-plugin-20130429
PKGREVISION=		1
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

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
SUFX=			bundle
.else
SUFX=			so
.endif

PLIST_SUBST+=		SUFX=${SUFX:Q}

pre-configure:
	cd ${WRKSRC} && aclocal -I m4 && autoheader && autoconf

.include "../../mail/dovecot2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
