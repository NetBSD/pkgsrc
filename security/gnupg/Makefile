# $NetBSD: Makefile,v 1.38 2002/11/24 16:52:05 chris Exp $
#

DISTNAME=	gnupg-1.2.1
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.gnupg.org/gcrypt/gnupg/ \
		ftp://ftp.planetmirror.com/pub/gnupg/ \
		ftp://ftp.ring.gr.jp/pub/pgp/ \
		ftp://gd.tuwien.ac.at/privacy/gnupg/ \
		ftp://ftp.jyu.fi/pub/crypt/gcrypt/ \
		ftp://ftp.cert.dfn.de/pub/tools/crypt/gcrypt/ \
		ftp://hal.csd.auth.gr/mirrors/gnupg/
EXTRACT_SUFX=	.tar.bz2
# don't remove this -- we may add idea.c.gz to it below
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	wiz@netbsd.org
HOMEPAGE=	http://www.gnupg.org/
COMMENT=	Privacy Guard, a public-Key encryption and digital signature utility

BUILD_USES_MSGFMT=	yes

CRYPTO=		yes
GNU_CONFIGURE=	yes
USE_BUILDLINK2=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS+=--enable-tiger --with-static-rnd=auto

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

INFO_FILES=	gpg.info gpgv.info

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=	USE_I586 USE_IDEA USE_OPENLDAP

.if defined(USE_I586) && ${USE_I586} == YES
# use assembler routines optimized for i586
ONLY_FOR_PLATFORM=	*-*-i386
MACHINE_GNU_ARCH=	i586
.endif

.if defined(USE_IDEA) && ${USE_IDEA} == YES
# use of IDEA as crypto function
LICENCE=	fee-based-commercial-use
DISTFILES+=	idea.c.gz
SITES_idea.c.gz=ftp://ftp.gnupg.dk/pub/contrib-dk/

pre-configure:
	${GZCAT} ${DISTDIR}/idea.c.gz > ${WRKSRC}/cipher/idea.c
.endif

.if defined(USE_OPENLDAP) && ${USE_OPENLDAP} == YES
.include "../../databases/openldap/buildlink2.mk"
PLIST_SUBST+=	OPENLDAP=""
.else
CONFIGURE_ARGS+=--disable-ldap
PLIST_SUBST+=	OPENLDAP="@comment "
.endif

test:
		cd ${WRKSRC} && make check

.include "../../converters/libiconv/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"
.include "../../lang/perl5/buildlink2.mk"

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
