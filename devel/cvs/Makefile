# $NetBSD: Makefile,v 1.34 2000/10/26 12:41:21 veego Exp $
#

DISTNAME=	cvs-1.11
PKGNAME=	${DISTNAME}nb1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.cvshome.org/pub/${DISTNAME}/ \
		${MASTER_SITE_GNU:=cvs/}

MAINTAINER=	tv@netbsd.org
HOMEPAGE=	http://www.cvshome.org/

GNU_CONFIGURE=	yes
USE_GTEXINFO=	yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
DEPENDS+=	zlib-*:../../devel/zlib
CFLAGS+=	-I${PREFIX}/include		# zlib.h
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
#CFLAGS+=		-I/usr/include/krb5		# krb5.h
#.else
#CONFIGURE_ARGS+=	--with-gssapi=no
#.endif

.if defined(RCS_LOCALID)
pre-fetch:
	@${ECHO} RCS_LOCALID is now replaced by the tag variable in CVSROOT/config.
.endif

CONFIGURE_ENV+=	perl_path=${PERL5}

INFO_FILES=	cvs.info cvsclient.info

.include "../../mk/bsd.pkg.mk"
