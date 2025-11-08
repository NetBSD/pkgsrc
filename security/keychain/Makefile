# $NetBSD: Makefile,v 1.48 2025/11/08 16:55:52 vins Exp $

DISTNAME=	keychain-2.9.8
PKGREVISION=	2
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=funtoo/}

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://www.funtoo.org/Keychain
COMMENT=	Nice ssh-agent front-end
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	groff perl:build pod2man

.include "../../mk/bsd.prefs.mk"

.if !exists(/usr/bin/ssh)
DEPENDS+=	openssh-[0-9]*:../../security/openssh
.endif

.if exists(${X11BASE}/bin/ssh-askpass)
ASKPASS_PROGRAM=	${X11BASE}/bin/ssh-askpass
.elif exists(/usr/libexec/ssh-askpass)
ASKPASS_PROGRAM=	/usr/libexec/ssh-askpass
.else
DEPENDS+=		ssh-askpass-[0-9]*:../../security/ssh-askpass
ASKPASS_PROGRAM=	${PREFIX}/bin/ssh-askpass
.endif

MAKE_ENV+=	ASKPASS=${ASKPASS_PROGRAM:Q}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/doc/${PKGBASE} \
			share/bash-completion/completions

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/keychain ${DESTDIR}${PREFIX}/bin/keychain
	${INSTALL_MAN} ${WRKSRC}/keychain.1	\
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/README.md	\
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

post-install:
	$(INSTALL_DATA) ${WRKSRC}/completions/keychain.bash	\
		${DESTDIR}${PREFIX}/share/bash-completion/completions
	${INSTALL_SCRIPT} ${FILESDIR}/startkeychain.sh		\
		${DESTDIR}${PREFIX}/bin/startkeychain
	${INSTALL_DATA} ${FILESDIR}/README.pkgsrc		\
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../mk/bsd.pkg.mk"
