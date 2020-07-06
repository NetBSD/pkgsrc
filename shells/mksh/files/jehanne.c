/*-
 * Copyright (c) 2017
 *	Giacomo Tesio <giacomo@tesio.it>
 *
 * Provided that these terms and disclaimer and all copyright notices
 * are retained or reproduced in an accompanying document, permission
 * is granted to deal in this work without restriction, including un-
 * limited rights to use, publicly perform, distribute, sell, modify,
 * merge, give away, or sublicence.
 *
 * This work is provided "AS IS" and WITHOUT WARRANTY of any kind, to
 * the utmost extent permitted by applicable law, neither express nor
 * implied; without malicious intent or gross negligence. In no event
 * may a licensor, author or contributor be held liable for indirect,
 * direct, other damage, loss, or other issues arising in any way out
 * of dealing in the work, even if advised of the possibility of such
 * damage or existence of a defect, except proven that it results out
 * of said person's immediate fault when using the work as intended.
 *-
 * Initialisation code for the Jehanne operating system (a Plan 9 de-
 * rivative, using GCC)
 */

static const char __rcsid[] __attribute__((__used__)) =
    "$MirOS: src/bin/mksh/jehanne.c,v 1.1 2017/12/22 16:30:00 tg Exp $";

#include <u.h>
#include <lib9.h>
#include <posix.h>

void
__application_newlib_init(int argc, char *argv[])
{
	rfork(RFFDG | RFREND | RFNOTEG);
	libposix_emulate_SIGCHLD();
}
