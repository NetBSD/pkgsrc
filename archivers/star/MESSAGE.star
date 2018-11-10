===========================================================================
$NetBSD: MESSAGE.star,v 1.1 2018/11/10 19:56:17 wiz Exp $

Note: The location of the ${PKGNAME_NOREV} `defaults' file has been set to

	${STAR_CONF}

This is the pkgsrc standard config file location, NOT the ${PKGNAME_NOREV}
standard location, which is /etc/default/star.

The reason for this is that pkgsrc packages should not use configuration
files outside ${LOCALBASE} unless they are explicitly set by the user.

===========================================================================
