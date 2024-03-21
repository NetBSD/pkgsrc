$NetBSD: patch-doc_index.md,v 1.1 2024/03/21 20:44:40 wiz Exp $

- escape double quotes
- fix TOC links

--- doc/index.md.orig	2024-03-11 17:59:51.000000000 +0000
+++ doc/index.md
@@ -112,7 +112,7 @@ The typographical conventions used by th
 
 @warning Look out for warnings!
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 
 Yet another scanner generator                                         {#intro1}
@@ -301,7 +301,7 @@ API that can be used as a stand-alone li
 and splitting input from strings, files and streams in regular C++ applications
 (i.e. applications that are not necessarily tokenizers for compilers).
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 
 And a flexible regex library                                          {#intro2}
@@ -1047,7 +1047,7 @@ In summary:
 
 \ref regex section has more information about the RE/flex regex library.
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 
 The RE/flex scanner generator                                         {#reflex}
@@ -1127,7 +1127,7 @@ digraph execute {
 The generated scanner executes actions (typically to produce tokens for a
 parser).  The actions are triggered by matching patterns to the input.
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 
 The reflex command line tool                                  {#reflex-command}
@@ -1169,7 +1169,7 @@ with Lex/Flex by generating the global `
 advanced input handling, which is more powerful than the traditional `FILE*`
 type `yyin`.
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 
 Options                                                       {#reflex-options}
@@ -1240,7 +1240,7 @@ check and use RE/flex options.  For exam
 option `−−lexer=NAME` or in the lexer specification with
 <i>`%%option lexer=NAME`</i>.
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 ### Scanner options                                   {#reflex-options-scanner}
 
@@ -1377,7 +1377,7 @@ or a tab character.  Actions in free spa
 blocks and user code must be placed in <i>`%{ %}`</i> blocks.  Patterns ending
 in an escape `\` continue on the next line.
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 ### Output files options                                {#reflex-options-files}
 
@@ -1468,7 +1468,7 @@ should compile the generated table file 
 `−−fast` eliminate the FSM construction overhead when the scanner is
 initialized.
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 ### Output code options                                  {#reflex-options-code}
 
@@ -1643,7 +1643,7 @@ default-constructed token type value is 
 reached.  For `int` this is `int()`, which is zero.  By setting
 `−−token-type=EOF` the value `EOF` is returned, for example.
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 ### Debugging options                                   {#reflex-options-debug}
 
@@ -1691,7 +1691,7 @@ This displays a summary of scanner stati
 
 This disables warnings.
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 ### Miscellaneous options                       {#reflex-options-miscellaneous}
 
@@ -1707,7 +1707,7 @@ This displays the current <b>`reflex`</b
 
 These options are enabled by default and have no effect.
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 
 Lexer specifications                                             {#reflex-spec}
@@ -1799,7 +1799,7 @@ will not return until the entire input i
 
 More details on these three lexer specification sections is presented next.
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 ### The definitions section                                 {#reflex-spec-defs}
 
@@ -2027,7 +2027,7 @@ for short) to declare inclusive states a
 
 See \ref reflex-states for more information about states.
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 ### The rules section                                      {#reflex-spec-rules}
 
@@ -2344,7 +2344,7 @@ These functions take an extra last `yysc
 generated with option `−−reentrant`.  This argument is a pointer to a lexer
 object.  See \ref reflex-reentrant for more details.
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 ### User code sections                                      {#reflex-spec-user}
 
@@ -2407,7 +2407,7 @@ The above uses a `FILE` descriptor to re
 of automatically decoding UTF-8/16/32 input.  Other permissible input sources
 are `std::istream`, `std::string`, `std::wstring`, `char*`, and `wchar_t*`.
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 
 Patterns                                                     {#reflex-patterns}
@@ -2421,7 +2421,7 @@ handle (except when specifically indicat
 ensures that the same pattern syntax can be used with any matcher engine
 library that RE/flex currently supports.
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 ### Pattern syntax                                     {#reflex-pattern-syntax}
 
@@ -2532,7 +2532,7 @@ patterns syntax.  These pattern should o
 
 Note that the characters `.` (dot), `\`, `?`, `*`, `+`, `|`, `(`, `)`, `[`,
 `]`, `{`, `}`, `^`, and `$` are meta-characters and should be escaped to match.
-Lexer specifications also include the `"` and `/` as meta-characters and these
+Lexer specifications also include the \c \" and `/` as meta-characters and these
 should be escaped to match.
 
 Spaces and tabs cannot be matched in patterns in lexer specifications.  To
@@ -2562,7 +2562,7 @@ problem does not apply to lexer specific
 converts to regex strings.  Fortunately, most C++ compilers ignore trigraphs
 unless in standard-conforming modes, such as `-ansi` and `-std=c++98`.
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 ### Character classes                                   {#reflex-pattern-class}
 
@@ -2666,7 +2666,7 @@ used as operands.  For example `{lower}{
 as an operand should expand into a POSIX character class containing ASCII
 characters only.
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 ### Character categories                                  {#reflex-pattern-cat}
 
@@ -3155,7 +3155,7 @@ and Coptic letters and differs from the 
 a specific Unicode block of Greek and Coptic characters only, which also
 includes unassigned characters.
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 ### Anchors and boundaries                             {#reflex-pattern-anchor}
 
@@ -3192,7 +3192,7 @@ underscore.
   `φ\<`     | matches `φ` that ends as a non-word
   `φ\>`     | matches `φ` that ends as a word
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 ### Indent/nodent/dedent                                {#reflex-pattern-dents}
 
@@ -3437,7 +3437,7 @@ matching `\j` until the variable is zero
 See \ref reflex-states for more information about start condition states.  See
 \ref reflex-pattern-negative for more information on negative patterns.
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 ### Negative patterns                                {#reflex-pattern-negative}
 
@@ -3454,7 +3454,7 @@ As another example, say we are searching
 occurrences of the word in quoted strings.  We can use the pattern
 `word|(?^".*?")` for this, where `(?^".*?")` matches all quoted strings that we
 want to ignore (to skip C/C++ quoted strings in source code input files, use
-the longer pattern `(?^"(\\.|\\\r?\n|[^\\\n"])*")`).
+the longer pattern <code>(?^\"(\\\\.|\\\\\\r?\\n|[^\\\\\\n\"])*\")</code>).
 
 A negative pattern can also be used to consume line continuations without
 affecting the indentation stops defined by indent marker `\i`.  Negative
@@ -3492,7 +3492,7 @@ matched in a negative pattern for the pa
 are never executed, because negative pattern matches are never returned by the
 matcher engine.
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 ### Lookahead                                       {#reflex-pattern-lookahead}
 
@@ -3504,7 +3504,7 @@ Boost.Regex and PCRE2 matchers support l
 supports lookahead at the end of a pattern, similar to \ref
 reflex-pattern-trailing.
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 ### Lookbehind                                     {#reflex-pattern-lookbehind}
 
@@ -3514,7 +3514,7 @@ A lookbehind pattern `φ(?<=ψ)` matches
 The RE/flex matcher does not support lookbehind.  Lookbehind patterns should
 not look too far behind, see \ref reflex-limitations.
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 ### Trailing context                                 {#reflex-pattern-trailing}
 
@@ -3528,7 +3528,7 @@ important \ref reflex-limitations to con
 to the construction of efficient FSMs for regular expressions.  The limitations
 apply to trailing context and lookaheads that the RE/flex matcher implements.
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 ### Unicode mode                                      {#reflex-pattern-unicode}
 
@@ -3557,7 +3557,7 @@ matcher converter flag `reflex::convert_
 patterns for use with the 8-bit based RE/flex, Boost.Regex, PCRE2, and
 std::regex regex libraries, see \ref regex-convert for more details.
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 ### Free space mode                                 {#reflex-pattern-freespace}
 
@@ -3585,7 +3585,7 @@ locally disable free-space mode in `φ`.
 conversion when the regex library does not support free-space mode modifiers,
 see \ref regex-convert for more details.
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 ### Multi-line mode                                 {#reflex-pattern-multiline}
 
@@ -3597,7 +3597,7 @@ Prepend `(?m)` to the regex to specify m
 locally enable multi-line mode in the sub-pattern `φ`.  Use `(?-m:φ)` to
 locally disable multi-line mode in `φ`.
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 ### Dotall mode                                        {#reflex-pattern-dotall}
 
@@ -3610,7 +3610,7 @@ dotall mode in `φ`.  The regex pattern 
 library does not support dotall mode modifiers, see \ref regex-convert for more
 details.
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 ### Case-insensitive mode                             {#reflex-pattern-anycase}
 
@@ -3623,7 +3623,7 @@ locally disable case-insensitive mode in
 conversion when the regex library does not support case-insensitive mode
 modifiers, see \ref regex-convert for more details.
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 ### Multiple mode modifiers                         {#reflex-pattern-modifiers}
 
@@ -3634,7 +3634,7 @@ modifiers may be applied to the same pat
 inline modifier `(?imsux-imsux:φ)`, where the mode modifiers before the dash
 are enabled and the mode modifiers after the dash are disabled.
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 ### Group captures                                   {#reflex-pattern-captures}
 
@@ -3660,7 +3660,7 @@ as follows:
 
 See also \ref reflex-posix-perl.
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 
 The Lexer/yyFlexLexer class                                     {#reflex-lexer}
@@ -3857,7 +3857,7 @@ option `−−class=NAME` to declare the
 `−−yyclass=NAME` to also enable `−−flex` compatibility with the `yyFlexLexer`
 class).  For details, see \ref reflex-inherit.
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 
 Inheriting Lexer/yyFlexLexer                                  {#reflex-inherit}
@@ -3917,7 +3917,7 @@ For example:
 The `int MyLexer::yylex()` method code is generated by <b>`reflex`</b> for this
 lexer specification.
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 
 Combining multiple lexers                                    {#reflex-multiple}
@@ -3945,7 +3945,7 @@ with `−−namespace=NAME`.  Or you can
 `−−outfile=NAME` and also `−−header-file=NAME` and ``−−tables-file=NAME` when
 header files and table files are used.
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 
 Switching input sources                                         {#reflex-input}
@@ -4391,7 +4391,7 @@ To prevent the scanner from initializing
 input with `LexerInput()`, use option `−−nostdinit`.
 
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 
 Multiple input sources                                 {#reflex-multiple-input}
@@ -4498,7 +4498,7 @@ C-based classic Flex example specificati
 </div>
 
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 
 Start condition states                                         {#reflex-states}
@@ -4723,7 +4723,7 @@ reflex-code-blocks.  All indented lines 
 <i>`%%option freespace`</i> allows patterns to be indented.  With this option
 all action code blocks must be bracketed.
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 
 Initial code blocks                                       {#reflex-code-blocks}
@@ -4803,7 +4803,7 @@ rules are matched.  For example:
 ~~~
 </div>
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 
 Interfacing with Bison/Yacc                                     {#reflex-bison}
@@ -4933,7 +4933,7 @@ The second option requires the generated
 macro is used or defined by Flex to redeclare the `yylex()` function signature,
 See \ref YYDECL for more information.
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 
 ### Bison and thread-safety                             {#reflex-bison-mt-safe}
@@ -4993,7 +4993,7 @@ Additional parameters may be passed to `
 <i>`%%option params="extra parameters"`</i> in the lexer specification.
 See \ref YYDECL.
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 
 ### Bison-cc                                                 {#reflex-bison-cc}
@@ -5073,7 +5073,7 @@ are `yy` and `parser` by default, respec
 the form `NAME1::NAME2::NAME3` or by separating the names by a dot as in
 `NAME1.NAME2.NAME3`.
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 
 ### Bison-cc & locations                           {#reflex-bison-cc-locations}
@@ -5152,7 +5152,7 @@ create a scanner and pass it to the `par
 ~~~
 </div>
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 
 ### Bison-complete                                     {#reflex-bison-complete}
@@ -5295,7 +5295,7 @@ Note that when the end of input is reach
 `yy::parser::make_EOF()` upon matching `<<EOF>>`.  This rule is optional.
 When omitted, the return value is `yy::parser::symbol_type(0)`.
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 
 ### Bison-complete & locations               {#reflex-bison-complete-locations}
@@ -5457,7 +5457,7 @@ Note that when the end of input is reach
 `yy::parser::make_EOF()` upon matching `<<EOF>>`.  This rule is optional.
 When omitted, the return value is `yy::parser::symbol_type(0, location())`.
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 
 ### Bison-bridge                                         {#reflex-bison-bridge}
@@ -5506,7 +5506,7 @@ should be used to create a new scanner a
 ~~~
 </div>
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 
 ### Bison-locations                                   {#reflex-bison-locations}
@@ -5571,7 +5571,7 @@ Note that with the `−−bison-location
 `YYLTYPE` argument that a Bison parser provides.  You can set `YYLTYPE` as
 an option <i>`%%option YYLTYPE=type`</i> in a lexer specification.
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 
 ### Bison-bridge & locations                   {#reflex-bison-bridge-locations}
@@ -5657,7 +5657,7 @@ the scanner in your program:
 ~~~
 </div>
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 
 ### Reentrant scanners                                      {#reflex-reentrant}
@@ -5757,7 +5757,7 @@ Because scanners are C++ classes, the `y
 is the `this` pointer.  Outside the scope of lexer methods a pointer to your
 `yyFlexLexer lexer` object should be used instead.
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 
 ### YY_DECL alternatives                                              {#YYDECL}
@@ -5793,7 +5793,7 @@ actions and the parser's semantic action
 
 See also \ref reflex-lexer.
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 
 Searching versus scanning                                      {#reflex-search}
@@ -5846,7 +5846,7 @@ This option only applies to the RE/flex 
 options `-f` (or `−−full`) and `-F` (or `−−fast`) to further increase
 performance.
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 
 POSIX versus Perl matching                                 {#reflex-posix-perl}
@@ -6031,7 +6031,7 @@ trailing context with the first rule as 
     echo "0" | ./lexer
     => 0
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 
 Debugging and profiling                                         {#reflex-debug}
@@ -6054,7 +6054,7 @@ performance given some input text to sca
 
 - Option `-v` (or `−−verbose`) displays a summary of scanner statistics.
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 ### Debugging
 
@@ -6066,7 +6066,7 @@ input.  The output displayed is of the f
 where NNN is the line number of the pattern in the lexer specification and TEXT
 is the matched text.
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 ### Profiling
 
@@ -6153,7 +6153,7 @@ relatively speaking the most expensive p
 are encountered on the input. We should focus our optimization effort there if
 we want to improve the overall speed of our JSON parser.
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 
 Examples                                                     {#reflex-examples}
@@ -6161,7 +6161,7 @@ Examples                                
 
 Some lexer specification examples to generate scanners with RE/flex.
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 ### Example 1
 
@@ -6204,7 +6204,7 @@ produces the global "yy" functions and v
 RE/flex scanners with Bison (Yacc) and with any other C code, assuming
 everything is compiled together with a C++ compiler.
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 ### Example 2
 
@@ -6257,7 +6257,7 @@ because the wc utility counts words deli
 (`iswspace`) whereas this program counts words made up from word characters
 combined with punctuation.
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 ### Example 3
 
@@ -6339,7 +6339,7 @@ We use `matcher().less(size() - 1)` to r
 ignores it.  We could also have used a lookahead pattern `"</"{name}/">"` where
 `X/Y` means look ahead for `Y` after `X`.
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 ### Example 4
 
@@ -6400,7 +6400,7 @@ characters into account.  To obtain the 
 use `matcher().border()`.  The `matcher()` object associated with the Lexer
 offers several other methods that Flex does not support.
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 ### Example 5
 
@@ -6430,7 +6430,7 @@ be ignored silently instead of being ech
 \ref reflex-search.  Option `%%fast` (`-F` or `−−fast`) generates an efficient
 FSM in direct code.
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 
 Limitations                                               {#reflex-limitations}
@@ -6490,7 +6490,7 @@ PCRE2 library limitations:
   available when new input is shifted into the internal buffer.  Only input on
   the current line from the start of the line to the match is guaranteed.
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 
 The RE/flex regex library                                              {#regex}
@@ -6525,7 +6525,7 @@ or `-lpcre2-8` if you use PCRE2 for matc
 If `libreflex` was not installed then linking with `-lreflex` fails.  See
 \ref link-errors on how to resolve this.
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 
 Boost matcher classes                                            {#regex-boost}
@@ -6628,7 +6628,7 @@ See \ref regex-methods for more details 
 
 See \ref regex-convert for more details on regex converters.
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 
 PCRE2 matcher classes                                            {#regex-pcre2}
@@ -6718,7 +6718,7 @@ See \ref regex-methods for more details 
 
 See \ref regex-convert for more details on regex converters.
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 
 std::regex matcher classes                                         {#regex-std}
@@ -6797,7 +6797,7 @@ See \ref regex-methods for more details 
 
 See \ref regex-convert for more details on regex converters.
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 
 The reflex::Matcher class                                      {#regex-matcher}
@@ -6859,7 +6859,7 @@ See \ref regex-methods for more details 
 
 See \ref regex-convert for more details on regex converters.
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 
 The reflex::Pattern class                                      {#regex-pattern}
@@ -6994,7 +6994,7 @@ method and functors.  Reversing the alte
 @note The `reflex::Pattern` regex forms support capturing groups at the
 top-level only, i.e. among the top-level alternations.
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 
 Regex converters                                               {#regex-convert}
@@ -7119,7 +7119,7 @@ example when the regex syntax is invalid
     }
 ~~~
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 
 Methods and iterators                                          {#regex-methods}
@@ -7149,7 +7149,7 @@ that apply filtering tokenization, and s
   `scan.begin()`...`scan.end()`   | tokenizer | continuous matches
   `split.begin()`...`split.end()` | splitter  | text between matches
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 ### matches                                            {#regex-methods-matches}
 
@@ -7193,7 +7193,7 @@ selector.  For example:
 
 See also \ref regex-methods-props.
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 ### find                                                  {#regex-methods-find}
 
@@ -7252,7 +7252,7 @@ selector.
 
 See also \ref regex-methods-props.
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 ### scan                                                  {#regex-methods-scan}
 
@@ -7311,7 +7311,7 @@ reached, use the `at_end()` method, see 
 
 See also \ref regex-methods-props.
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 ### split                                                {#regex-methods-split}
 
@@ -7369,7 +7369,7 @@ and is also used with any other RE/flex 
 
 See also \ref regex-methods-props.
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 ### Properties of a match                                {#regex-methods-props}
 
@@ -7545,7 +7545,7 @@ When executed this code prints:
     accept: 1 text: brown size: 5 line: 1 column: 8 first: 8 last: 13
     accept: 1 text: cow size: 3 line: 1 column: 14 first: 14 last: 17
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 ### Public data members                                        {#regex-members}
 
@@ -7565,7 +7565,7 @@ The functors provide `begin()` and `end(
 hold the necessary state information for the iterators.  A functor invocation
 essentially invokes the corresponding method listed in \ref regex-methods.
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 ### Pattern methods                                    {#regex-methods-pattern}
 
@@ -7582,7 +7582,7 @@ the following methods:
 The first method returns a reference to the matcher, so multiple method
 invocations may be chained together.
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 ### Input methods                                        {#regex-methods-input}
 
@@ -7672,7 +7672,7 @@ to immediately force reading the sources
 
 For details of the `reflex::Input` class, see \ref regex-input.
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 
 The Input class                                                  {#regex-input}
@@ -7682,7 +7682,7 @@ A matcher may accept several types of in
 source at a time.  Input to a matcher is represented by a single
 `reflex::Input` class instance that the matcher uses internally.
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 ### Assigning input                                       {#regex-input-assign}
 
@@ -7700,7 +7700,7 @@ override the file encoding when no UTF B
 ISO-8859-1 through ISO-8859-15, CP 1250 through 1258, CP 437, CP 850, CP 858,
 KOI8, MACROMAN, EBCDIC, and other encodings to UTF-8, see \ref regex-input-file.
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 ### Input strings                                        {#regex-input-strings}
 
@@ -7735,7 +7735,7 @@ construction overheads.
 (NUL) character and the first `\0` terminates matching.  To match strings
 and binary input that contain `\0`, use `std::string` or `std::istringstream`.
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 ### Input streams                                        {#regex-input-streams}
 
@@ -7743,7 +7743,7 @@ An input object constructed from a `std:
 passes the input text to the matcher engine.  The stream should contain ASCII
 and may contain UTF-8.
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 ### FILE encodings                                          {#regex-input-file}
 
@@ -7854,7 +7854,7 @@ your code page to construct an input obj
 This example translates all control characters and characters above 127 to
 spaces before matching.
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 ### Input properties                                  {#regex-input-properties}
 
@@ -7870,7 +7870,7 @@ To obtain the properties of an input sou
   `file()`    | the current `FILE*` file descriptor or NULL
   `istream()` | a `std::istream*` pointer to the current stream object or NULL
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 ### Input streambuf                                    {#regex-input-streambuf}
 
@@ -7917,7 +7917,7 @@ version may not be suitable for interact
 
 See also \ref regex-input-dosstreambuf.
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 ### Windows CRLF pairs                              {#regex-input-dosstreambuf}
 
@@ -7995,7 +7995,7 @@ version may not be suitable for interact
 
 See also \ref regex-input-streambuf.
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 
 Examples                                                      {#regex-examples}
@@ -8003,7 +8003,7 @@ Examples                                
 
 This section includes several examples to demonstrate the concepts discussed.
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 ### Example 1
 
@@ -8059,7 +8059,7 @@ When executed this code prints:
     Circus Flying Monty Python's
 
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 ### Example 2
 
@@ -8126,7 +8126,7 @@ be used, since both support group captur
 
 See also Example 8 below for a more powerful URL pattern matcher.
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 ### Example 3
 
@@ -8154,7 +8154,7 @@ When executed this code prints:
 
     Monty, Flying, Circus, 
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 ### Example 4
 
@@ -8176,7 +8176,7 @@ stream:
     std::cout << lines << " " << words << " " << chars << std::endl;
 ~~~
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 ### Example 5
 
@@ -8213,7 +8213,7 @@ When executed this code prints:
     Token = 2: matched 'hotdogs' with '(\\w*dog\\w*)'
     Token = 4: matched '!' with '(.)'
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 ### Example 6
 
@@ -8260,7 +8260,7 @@ When executed this code prints:
     3: 601112345678901234
     4: 38812345678901
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 ### Example 7
 
@@ -8298,7 +8298,7 @@ matches, but that feature appears to be 
         << std::endl;
 ~~~
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 ### Example 8
 
@@ -8398,7 +8398,7 @@ this code prints:
     query key: name, value: reflex
     query key: license, value: BSD-3
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 ### Example 9
 
@@ -8493,13 +8493,13 @@ This sets the file encoding to ISO-8859-
 in the file.  Files with a UTF BOM are always decoded as UTF, which cannot be
 overruled.
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 
 Tips, tricks, and gotchas                                             {#tricks}
 =========================
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 
 Errors when declaring extern yyin, yytext, yylineno              {#extern-yyin}
@@ -8567,7 +8567,7 @@ restricted to `FILE*` types and accepts 
 
 See \ref reflex-input.
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 
 Compilation errors when using yy functions                      {#yy-functions}
@@ -8612,7 +8612,7 @@ Note that the `yyinput()` macro expands 
 to generate global `yy` variables and functions stored in the global
 `YY_SCANNER` object.
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 
 Invalid UTF encodings and the dot pattern                        {#invalid-utf}
@@ -8669,7 +8669,7 @@ character class by intersecting the clas
 in classes that are within range U+0000 to U+10FFFF and excludes surrogate
 halves.
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 
 Error reporting and recovery                                          {#errors}
@@ -8965,7 +8965,7 @@ enabled with:
 For more details on Bison error messaging, resolution, and LAC, please see the
 Bison documentation.
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 
 On using setlocale                                                 {#setlocale}
@@ -9017,7 +9017,7 @@ not on all systems (I'm looking at you, 
     ifs.close();
 ~~~
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 
 Scanning ISO-8859-1 (latin-1) files with a Unicode scanner        {#iso-8859-1}
@@ -9043,7 +9043,7 @@ When a BOM is detected the scanner switc
 
 See \ref regex-input-file to set file encodings.
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 
 Files with CRLF pairs                                                   {#crlf}
@@ -9079,7 +9079,7 @@ Reading a file in the default "text mode
 latest RE/flex releases automatically switch `FILE*` input to binary mode on
 Windows systems when the file is encoded in UTF-16 or UTF-32, but not UTF-8.
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 
 Handling old Macintosh files containing CR newlines                       {#cr}
@@ -9120,7 +9120,7 @@ normalizing to UTF-8:
 Then use the `input` object to read `stdin` or any other `FILE*`.  See also
 \ref regex-input-file.
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 
 Lazy repetitions                                                        {#lazy}
@@ -9132,7 +9132,7 @@ useless when the regex pattern after the
 For example, `.*?a?` only matches one `a` or nothing at all, because `a?`
 permits an empty match.
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 
 Lazy optional patterns and trigraphs                               {#trigraphs}
@@ -9154,7 +9154,7 @@ which the C/C++ compiler translates to `
 
 Otherwise, lazy optional pattern constructs will appear broken.
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 
 Repeately switching to the same input                              {#switching}
@@ -9187,7 +9187,7 @@ If you need to read a file or stream aga
    which means that you cannot reliably move to an arbitrary location in the
    file to start reading when the file is encoded in UTF-8, UTF-16, or UTF-32.
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 
 Where is FlexLexer.h?                                              {#flexlexer}
@@ -9206,7 +9206,7 @@ The `FlexLexer` class defined in <i>`ref
 of the generated `yyFlexLexer` class.  A name for the generated lexer class can
 be specified with option `−−lexer=NAME`.
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 
 Interactive input with GNU readline                                 {#readline}
@@ -9307,7 +9307,7 @@ example:
 ~~~
 </div>
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 
 Registering a handler to support non-blocking reads                 {#nonblock}
@@ -9397,7 +9397,7 @@ checking if an error conditions exist on
 `ferror()`.  Errors are cleared with `clearerr()`.  Note that a non-blocking
 read that returns zero always produces nonzero `ferror()` values.
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 
 Undefined symbols and link errors                                {#link-errors}
@@ -9444,7 +9444,7 @@ RE/flex applications:
   <i>`lex.yy.h`</i> with the lexer class to include in the source code of your
   lexer application.
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 
 Minimized library and cross compiling                                {#linking}
@@ -9471,7 +9471,7 @@ and ARM NEON/AArch64 are used to  speed 
 in the library.  However, these optimizations are applicable to searching with
 the `find()` method and are not applicable to scanners.
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 
 How to minimize runtime memory usage                                {#memusage}
@@ -9501,7 +9501,7 @@ input buffer:
 
 @warning The value of `REFLEX_BUFSZ` should not be less than 8192.
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 
 MSVC++ compiler bug                                                     {#msvc}
@@ -9525,7 +9525,7 @@ Instead, we should write the following:
       std::cout << match.text() << std::endl;
 ~~~
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 
 Bugs                                                                    {#bugs}
@@ -9540,7 +9540,7 @@ old with new versions may cause problems
 RE/flex header files are imported into your project but an old RE/flex library
 version is still linked with your code, the library may likely misbehave.
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 
 Installing RE/flex                                                  {#download}
@@ -9549,7 +9549,7 @@ Installing RE/flex                      
 Download RE/flex from [SourceForge](https://sourceforge.net/projects/re-flex)
 or visit the RE/flex GitHub [repository](https://github.com/Genivia/RE-flex).
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 
 License and copyright                                                {#license}
@@ -9588,6 +9588,6 @@ includes the ability to reuse all or par
 The Free Software Foundation maintains a
 [BSD-3 License Wiki](http://directory.fsf.org/wiki/License:BSD_3Clause).
 
-🔝 [Back to table of contents](#)
+🔝 [Back to table of contents](#mainpage)
 
 Copyright (c) 2016-2020, Robert van Engelen, Genivia Inc. All rights reserved.
