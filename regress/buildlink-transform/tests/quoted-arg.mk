# $NetBSD: quoted-arg.mk,v 1.1 2004/09/07 10:27:57 jlam Exp $

.PHONY: quoted-arg
do-regress: quoted-arg
quoted-arg:
	@test='-D"DEFAULT_MODULE_PATH=\"${LOCALBASE}/lib/security/\""';	\
	expected='-D"DEFAULT_MODULE_PATH=\"${LOCALBASE}/lib/security/\""'; \
	${TEST_RESULT}
