# $NetBSD: Makefile,v 1.18 2002/09/01 15:30:11 kim Exp $

DISTNAME=	irrd2.1.4
PKGNAME=	irrd-2.1.4
CATEGORIES=	net
MASTER_SITES=	http://www.irrd.net/ \
		ftp://ftp.merit.edu/radb/irrd/ \
		ftp://ftp.merit.edu/radb/irrd/old_releases/

MAINTAINER=	kim@tac.nyc.ny.us
HOMEPAGE=	http://www.irrd.net/
COMMENT=	Internet Routing Registry Daemon

DEPENDS+=	gnupg-[0-9]*:../../security/gnupg
DEPENDS+=	wget-[0-9]*:../../net/wget

USE_PERL5=	# defined

WRKSRC=		${WRKDIR}/${DISTNAME}/src

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-gdbm
CONFIGURE_ARGS+=--disable-thread
CONFIGURE_ENV+=	YACC=bison

CPPFLAGS+=	-I${LOCALBASE}/include
CFLAGS+=	-g

IRRD_CACHER=	irrdcacher ripe2rpsl update_source

post-build:
	@cd ${WRKSRC}/programs/irrdcacher ; \
	set -x ; \
	for i in ${IRRD_CACHER} ; \
	do \
	    ${MV} $$i $$i.bak ; \
	    ${SED} -e 's%/usr/bin/perl%${PERL5}%' < $$i.bak > $$i ; \
	done

post-install:
	@cd ${WRKSRC}/programs/IRRd && ${MAKE} install-man
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
