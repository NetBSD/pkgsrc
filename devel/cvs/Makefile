# $NetBSD: Makefile,v 1.38 2001/03/04 01:08:01 assar Exp $
#

DISTNAME=	cvs-1.11
PKGNAME=	${DISTNAME}nb1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.cvshome.org/pub/${DISTNAME}/ \
		${MASTER_SITE_GNU:=cvs/}

MAINTAINER=	tv@netbsd.org
HOMEPAGE=	http://www.cvshome.org/
COMMENT=	Concurrent Versions System

GNU_CONFIGURE=	yes
USE_GTEXINFO=	yes

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} == "SunOS")
DEPENDS+=	zlib-*:../../devel/zlib
CFLAGS+=	-I${PREFIX}/include		# zlib.h
.endif

.if defined(KERBEROS)
CONFIGURE_ARGS+=	--with-krb4=/usr --enable-encryption
CONFIGURE_ARGS+=	--with-gssapi=/usr
.endif

.if defined(RCS_LOCALID)
pre-fetch:
	@${ECHO} RCS_LOCALID is now replaced by the tag variable in CVSROOT/config.
.endif

CONFIGURE_ENV+=	perl_path=${PERL5}

INFO_FILES=	cvs.info cvsclient.info

.include "../../mk/bsd.pkg.mk"
