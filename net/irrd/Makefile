# $NetBSD: Makefile,v 1.10 2000/10/21 22:49:17 wiz Exp $
#

DISTNAME=	irrd2.0a-Aug22-2000
PKGNAME=	irrd-2.0.0.20000822
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.merit.edu/radb/irrd/source/ \
		ftp://ftp.merit.edu/radb/irrd/source/old_releases/

MAINTAINER=	kim@tac.nyc.ny.us
HOMEPAGE=	http://www.irrd.net/

BUILD_DEPENDS+=	autoreconf:../../devel/autoconf
BUILD_DEPENDS+=	bison:../../devel/bison
DEPENDS+=	gdbm-*:../../databases/gdbm
DEPENDS+=	pgp5-*:../../security/pgp5
DEPENDS+=	wget-*:../../net/wget

USE_PERL5=	# defined

WRKSRC=		${WRKDIR}/${DISTNAME}/src

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-gdbm
CONFIGURE_ARGS+=--disable-thread
CONFIGURE_ENV+=	YACC=bison
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}"

CPPFLAGS+=	-I${LOCALBASE}/include
CFLAGS+=	-g

pre-configure:
	@(cd ${WRKSRC} && autoreconf)

IRRD_CACHER=	irrdcacher ripe2rpsl update_source

post-build:
	@cd ${WRKSRC}/programs/irrdcacher ; \
	set -x ; \
	for i in ${IRRD_CACHER} ; \
	do \
	    ${MV} $$i $$i.bak ; \
	    ${SED} -e 's%/usr/local/bin/perl%${PERL5}%' < $$i.bak > $$i ; \
	done

post-install:
	@cd ${WRKSRC}/programs/irrdcacher ; \
	set -x ; \
	for i in ${IRRD_CACHER} ; \
	do \
	    ${INSTALL_SCRIPT} $$i ${PREFIX}/sbin ; \
	done

.include "../../mk/bsd.prefs.mk"

.if defined(USE_INET6) && ${USE_INET6} == "YES"
# default
# CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.include "../../mk/bsd.pkg.mk"
