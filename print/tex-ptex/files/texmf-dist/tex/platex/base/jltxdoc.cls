%%
%% This is file `jltxdoc.cls',
%% generated with the docstrip utility.
%%
%% The original source files were:
%%
%% jltxdoc.dtx  (with options: `class')
%% 
%% IMPORTANT NOTICE:
%% 
%% For the copyright see the source file.
%% 
%% Any modified versions of this file must be renamed
%% with new filenames distinct from jltxdoc.cls.
%% 
%% For distribution of the original source see the terms
%% for copying and modification in the file jltxdoc.dtx.
%% 
%% This generated file may be distributed as long as the
%% original source files, as listed above, are part of the
%% same distribution. (The sources need not necessarily be
%% in the same archive or directory.)
%% File: jltxdoc.dtx
%% \CharacterTable
%%  {Upper-case    \A\B\C\D\E\F\G\H\I\J\K\L\M\N\O\P\Q\R\S\T\U\V\W\X\Y\Z
%%   Lower-case    \a\b\c\d\e\f\g\h\i\j\k\l\m\n\o\p\q\r\s\t\u\v\w\x\y\z
%%   Digits        \0\1\2\3\4\5\6\7\8\9
%%   Exclamation   \!     Double quote  \"     Hash (number) \#
%%   Dollar        \$     Percent       \%     Ampersand     \&
%%   Acute accent  \'     Left paren    \(     Right paren   \)
%%   Asterisk      \*     Plus          \+     Comma         \,
%%   Minus         \-     Point         \.     Solidus       \/
%%   Colon         \:     Semicolon     \;     Less than     \<
%%   Equals        \=     Greater than  \>     Question mark \?
%%   Commercial at \@     Left bracket  \[     Backslash     \\
%%   Right bracket \]     Circumflex    \^     Underscore    \_
%%   Grave accent  \`     Left brace    \{     Vertical bar  \|
%%   Right brace   \}     Tilde         \~}
%%

\NeedsTeXFormat{pLaTeX2e}
\ProvidesClass{jltxdoc}[1997/07/29 v1.0b Standard pLaTeX file]
\DeclareOption*{\PassOptionsToClass{\CurrentOption}{ltxdoc}}
\ProcessOptions
\LoadClass{ltxdoc}
\renewcommand{\normalsize}{%
    \@setfontsize\normalsize\@xpt{15}%
  \abovedisplayskip 10\p@ \@plus2\p@ \@minus5\p@
  \abovedisplayshortskip \z@ \@plus3\p@
  \belowdisplayshortskip 6\p@ \@plus3\p@ \@minus3\p@
   \belowdisplayskip \abovedisplayskip
   \let\@listi\@listI}
\renewcommand{\small}{%
  \@setfontsize\small\@ixpt{11}%
  \abovedisplayskip 8.5\p@ \@plus3\p@ \@minus4\p@
  \abovedisplayshortskip \z@ \@plus2\p@
  \belowdisplayshortskip 4\p@ \@plus2\p@ \@minus2\p@
  \def\@listi{\leftmargin\leftmargini
              \topsep 4\p@ \@plus2\p@ \@minus2\p@
              \parsep 2\p@ \@plus\p@ \@minus\p@
              \itemsep \parsep}%
  \belowdisplayskip \abovedisplayskip}
\normalsize
\setlength\parindent{1zw}
\providecommand*{\file}[1]{\texttt{#1}}
\providecommand*{\pstyle}[1]{\textsl{#1}}
\providecommand*{\Lcount}[1]{\textsl{\small#1}}
\providecommand*{\Lopt}[1]{\textsf{#1}}
\providecommand\dst{{\normalfont\scshape docstrip}}
\providecommand\NFSS{\textsf{NFSS}}
\newcounter{@clineno}
\def\mlineplus#1{\setcounter{@clineno}{\arabic{CodelineNo}}%
   \addtocounter{@clineno}{#1}\arabic{@clineno}}
\def\tsample#1{%
  \hbox to\linewidth\bgroup\vrule width.1pt\hss
    \vbox\bgroup\hrule height.1pt
      \vskip.5\baselineskip
      \vbox to\linewidth\bgroup\tate\hsize=#1\relax\vss}
\def\endtsample{%
      \vss\egroup
      \vskip.5\baselineskip
    \hrule height.1pt\egroup
  \hss\vrule width.1pt\egroup}
\def\DisableCrossrefs{\@bsphack\scan@allowedfalse\@esphack}
\def\EnableCrossrefs{\@bsphack\scan@allowedtrue
   \def\DisableCrossrefs{\@bsphack\scan@allowedfalse\@esphack}\@esphack}
\xspcode"5C=3 %% \
\xspcode"22=3 %% "
\endinput
%%
%% End of file `jltxdoc.cls'.
