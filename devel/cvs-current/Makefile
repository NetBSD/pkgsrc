# $NetBSD: Makefile,v 1.12 2000/10/18 13:03:47 wiz Exp $
#

DISTNAME=       cvs-1.10.8
CATEGORIES=	devel
MASTER_SITES=   ftp://ftp.cvshome.org/pub/${DISTNAME}/

MAINTAINER=	cjs@netbsd.org
HOMEPAGE=	http://www.cvshome.org/

GNU_CONFIGURE=	yes
USE_GTEXINFO=	yes

BUILD_DEFS+=	RCS_LOCALID

IGNORE=		"devel/cvs contains a newer version of cvs"

.if exists(/usr/bin/cvs)  
IGNORE=		"${PKGNAME} is part of your NetBSD distribution"
.endif

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
DEPENDS+=	zlib-*:../../devel/zlib
.endif

.if defined(KERBEROS) && ${KERBEROS} == 4
USE_KERBEROS=	yes
CONFIGURE_ARGS+=	--with-krb4=/usr --enable-encryption
.else
CONFIGURE_ARGS+=	--with-krb4=no
.endif

# XXX KERBEROS 5 SUPPORT BROKEN WITH HEIMDAL
#.if defined(KERBEROS) && ${KERBEROS} == 5
#USE_KERBEROS=	yes
#CONFIGURE_ARGS+=	--with-gssapi
#.else
#CONFIGURE_ARGS+=	--with-gssapi=no
#.endif

.if defined(RCS_LOCALID)
CFLAGS+=	-DLOCALID=\"\\\"${RCS_LOCALID}\\\"\"
.endif

CONFIGURE_ENV+=	perl_path=${PERL5}

INFO_FILES=	cvs.info cvsclient.info

.include "../../mk/bsd.pkg.mk"
