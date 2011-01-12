/*	$NetBSD: package-list.c,v 1.2 2011/01/12 08:47:52 tron Exp $	*/

/*-
 * Copyright (c) 2001-2011 The NetBSD Foundation, Inc.
 * All rights reserved.
 *
 * This code is derived from software contributed to The NetBSD Foundation
 * by Matthias Scheler.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include "package-list.h"

#include <stdlib.h>
#include <string.h>

PListEntry *
PListInsert(PListEntry **Tree,char *Name)
{
	PListEntry *Node;

	while ((Node = *Tree) != NULL) {
		Tree = (strcmp(Name, Node->pe_Name) <0) ?
		    &Node->pe_Left : &Node->pe_Right;
	}

	if ((Node = calloc(1, sizeof (PListEntry) + strlen(Name))) == NULL) {
		perror("calloc");
		exit(EXIT_FAILURE);
	}

	(void)strcpy(Node->pe_Name, Name);

	return *Tree = Node;
}

PListEntry *
PListFind(PListEntry *Tree, char *Name)
{
	while (Tree != NULL) {
		int Result;

		if ((Result = strcmp(Name, Tree->pe_Name)) == 0) break;
		Tree = (Result < 0) ? Tree->pe_Left : Tree->pe_Right;
	}

	return Tree;
}

static void
PListWalk(PListEntry *Tree, PListEntryFunc Func, FILE *Out)
{
	while (Tree != NULL) {
		if (Tree->pe_Childs[0] != NULL)
			PListWalk(Tree->pe_Childs[0], Func, Out);
		Func(Tree, Out);
		Tree = Tree->pe_Childs[1];
	}
}

static void
PListEntryFile(PListEntry *node, FILE *out)
{
	(void)fprintf(out, "%s\n", node->pe_Name);
}

static void
PListEntryMakeDir(PListEntry *node, FILE *out)
{
	if (node->pe_DirEmpty)
		(void)fprintf(out, "@pkgdir %s\n", node->pe_Name);
}

void
PListWrite(PListEntry *files, PListEntry *dirs, FILE *out)
{
	PListWalk(files, PListEntryFile, out);
	PListWalk(dirs, PListEntryMakeDir, out);
}
