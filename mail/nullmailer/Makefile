# $NetBSD: Makefile,v 1.1.1.1.2.1 2002/06/23 18:51:48 jlam Exp $

DISTNAME=		nullmailer-1.00RC5
CATEGORIES=		mail
MASTER_SITES=		http://untroubled.org/nullmailer/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://untroubled.org/nullmailer/
COMMENT=		Simple relay-only mail transport agent

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+= 	--sysconfdir=${PKG_SYSCONFDIR} --localstatedir=/var

INSTALL_TARGET=		install install-data-local install-root

.include "../../mk/bsd.prefs.mk"

NULLMAILER_GROUP?=	nullmail
NULLMAILER_USER?=	nullmail
PKG_GROUPS?=		${NULLMAILER_GROUP}
PKG_USERS?=		${NULLMAILER_USER}

MAKE_ENV+=		NULLMAILER_GROUP=${NULLMAILER_GROUP}
MAKE_ENV+=		NULLMAILER_USER=${NULLMAILER_USER}

PLIST_SUBST+=		PKG_SYSCONFDIR=${PKG_SYSCONFDIR}		\
			NULLMAILER_GROUP=${NULLMAILER_GROUP}		\
			NULLMAILER_USER=${NULLMAILER_USER}

pre-configure:
	for f in ${WRKSRC}/doc/nullmailer-send.8; do			\
		${SED} -e 's:@PREFIX@:${PREFIX}:g'			\
			-e 's:@PKG_SYSCONFDIR@:${PKG_SYSCONFDIR}:g'	\
		$$f > $$f.tmp && ${MV} -f $$f.tmp $$f;			\
	done

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/nullmailer
	cd ${WRKSRC} && ${INSTALL_DATA} AUTHORS BUGS COPYING ChangeLog	\
		HOWTO NEWS README TODO ${PREFIX}/share/doc/nullmailer

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
